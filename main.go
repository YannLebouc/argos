package main

import (
	"fmt"
	"net"
	"os"
)

const (
	connectionType = "tcp"
	bufferSize     = 1024
)

func main() {
	cfg := LoadConfig()

	fmt.Println("Starting TCP server on port : " + cfg.Port)

	listen, err := net.Listen(connectionType, cfg.Port)
	if err != nil {
		fmt.Printf("error starting server : %s", err.Error())
		os.Exit(1)
	}
	defer listen.Close()

	fmt.Println("TCP server now listening on address : " + listen.Addr().String())
}
