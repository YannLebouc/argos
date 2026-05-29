package main

import (
	"fmt"
	"net"
	"os"
)

const (
	host           = "localhost"
	port           = "8080"
	connectionType = "tcp"
	bufferSize     = 1024
	address        = host + ":" + port
)

func main() {
	fmt.Println("Starting TCP server on port : " + port)

	listen, err := net.Listen(connectionType, address)
	if err != nil {
		fmt.Printf("error starting server : %s", err.Error())
		os.Exit(1)
	}
	defer listen.Close()

	fmt.Println("TCP server now listening on address : " + listen.Addr().String())
}
