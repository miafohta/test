package main

import (
        "db"
        "db/models"
        "fmt"
        pb "gRPC/watchlist/proto"
        "golang.org/x/net/context"
        "google.golang.org/grpc"
        "google.golang.org/grpc/reflection"
        "log"
        "net"
        "strconv"
        "time"
)

const (
        port = ":50051"
)

type server struct{}

type Watchlists struct {
        user_id int
        movies  []models.Movie
        created time.Time
        update  time.Time
}


func (s *server) AddWatchlist(ctx context.Context, in *pb.WatchlistReq) (*pb.WatchlistRep, error) {
        mi := int(in.MovieId)
        ui := int(in.UserId)
        wid := 1
        var DB *db.DB
        var err error

        if DB, err = getDBConn(); err != nil {
                log.Fatalf("Error GetWatchlist &s", err)
                return nil, err
        }

        // Create new user_move_watch_list
        userlist := models.UserMovieWatchList{
                WatchListID: wid,
                UserID:      ui,
                MovieID:     mi,
        }

        // Check if record exists before creating it.
        if DB.GormDB.Where("user_id = ? and watchlist_id = ? and movie_id = ?",
                ui, wid, mi).Find(&userlist).
                RecordNotFound() {
                if err = DB.GormDB.Create(&userlist).Error; err != nil {
                        return nil, err
                }
        }
        // Preload the data from move and watchlist tables into the new userlist record.
        DB.GormDB.Preload("Movie").Preload("WatchList").Find(&userlist)

        // Print and see data
        //l.NoticeF("JSON: %v", models.ToJSON(&userlist))
        var js string
        js = models.ToJSON(&userlist)
       mmi := strconv.Itoa(mi)
        return &pb.WatchlistRep{Message: "The movie is added" + mmi + " Watchlist:" + js}, nil
}

func (s *server) DeleteWatchlist(ctx context.Context, in *pb.WatchlistReq) (*pb.WatchlistRep, error) {
        mi := int(in.MovieId)
        ui := int(in.UserId)
        si := int(in.SiteId)
        var DB *db.DB
        var err error

        if DB, err = getDBConn(); err != nil {
                log.Fatalf("Error GetWatchlist &s", err)
                return nil, err
        }

        // Create new user_move_watch_list
        userlist := models.UserMovieWatchList{
                UserID:  ui,
                MovieID: mi,
        }

        // Check if record exists before creating it.
        if DB.GormDB.Where("user_id = ? and movie_id = ?", ui, mi).Find(&userlist).RecordNotFound() {
                return nil, fmt.Errorf("record not found:%v", mi)
        }

        if err = DB.GormDB.Delete(&userlist).Error; err != nil {
                return nil, err
        }

        model, err := models.NewUserMovieWatchList(DB.GormDB)
        var watchlists []models.UserMovieWatchList

        if err := model.GetUserWatchLists().Where("user_id = ? and site_id = ?", ui, si).Limit(2).Find(&watchlists).Error; err != nil {
                return nil, err
       var mp []models.Movie
        for _, v := range watchlists {
                m := v.Movie
                mp = append(mp, m)
        }
        var usi = int(ui)
        wm := &Watchlists{
                user_id: usi,
                movies:  mp,
        }

        var js string
        js = models.ToJSON(&wm)
        mmi := strconv.Itoa(mi)
        return &pb.WatchlistRep{Message: "The movie " + mmi + " is deleted from the list. Watchlist updated:" + js}, nil

        //return &pb.WatchlistRep{Message: "The movie  is deleted from the list. Watchlist updated:"}, nil
}

func (s *server) GetWatchlist(stx context.Context, in *pb.WatchlistReq) (*pb.WatchlistRep, error) {
        ui := in.UserId
        si := in.SiteId
        var DB *db.DB
        var err error

        if DB, err = getDBConn(); err != nil {
                log.Fatalf("Error GetWatchlist &s", err)
                return nil, err
        }

        model, _ := models.NewUserMovieWatchList(DB.GormDB)
        var watchlists []models.UserMovieWatchList

        if err := model.GetUserWatchLists().Where("user_id = ? and site_id = ?", ui, si).Limit(2).Find(&watchlists).Error; err != nil {
                return nil, err
        }
       var mp []models.Movie
        for _, v := range watchlists {
                m := v.Movie
                mp = append(mp, m)
        }
        var usi = int(ui)
        wm := &Watchlists{
                user_id: usi,
                movies:  mp,
        }
        fmt.Printf("%v", &wm)
        var js string
        js = models.ToJSON(&wm)
        return &pb.WatchlistRep{Message: "The Watchlist : " + js}, nil
}

func getDBConn() (*db.DB, error) {
        var DB *db.DB
        var err error

        log.Printf("GetDBConn started")
        dbconf := &db.Conf{
                Dialect:      "xxxxxxxx",
                Username:     "xxxxxx",
                DBName:       "xxxxxxx",
                Port:         12345,
                Host:         "xxxxxxxx",
                Password:     "xxxxxxxxx",
                MaxOpenConns: 1,
                MaxIdleConns: 1}

        if DB, err = db.New(dbconf); err != nil {
                return nil, err
        }

        return DB, err
}

func main() {
        lis, err := net.Listen("tcp", port)
        if err != nil {
                log.Fatalf("failed to listen: %v", err)
        }
        s := grpc.NewServer()
        pb.RegisterWatchlistServer(s, &server{})
        // Register reflection service on gRPC server.
        reflection.Register(s)
        if err := s.Serve(lis); err != nil {
                log.Fatalf("failed to serve: %v", err)
        }
}

