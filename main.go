package main

import (
	"log/slog"
	"net"
	"os"
)

const (
	connectionType = "tcp"
	bufferSize     = 1024
)

func main() {
	cfg := LoadConfig()
	InitLogger(&cfg)

	slog.Info("Starting TCP server", "PORT", cfg.Port)

	listen, err := net.Listen(connectionType, cfg.Port)
	if err != nil {
		slog.Error("error while starting the server...", slog.String("error", err.Error()))
		os.Exit(1)
	}
	defer listen.Close()

	slog.Info("TCP server now listening : ", slog.String("address", listen.Addr().String()))
}
