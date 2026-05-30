package main

import (
	"log"
	"os"

	"github.com/joho/godotenv"
)

type Config struct {
	Environment string
	Port        string
}

func getEnv(key string, fallback string) string {
	value := os.Getenv(key)

	if value == "" {
		return fallback
	}

	return value
}

func getMandatoryEnv(key string) string {
	value := os.Getenv(key)

	if key == "" {
		log.Fatalf("missing mandatory environment variabl : %s", key)
	}

	return value
}

func LoadConfig() Config {
	_ = godotenv.Load()

	return Config{
		Environment: getMandatoryEnv("ARGOS_ENV"),
		Port:        getEnv("ARGOS_LISTEN_PORT", ":8080"),
	}
}
