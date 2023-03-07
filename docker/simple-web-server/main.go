package main

import (
	"github.com/gin-gonic/gin"
	"net/http"
)

func main() {
	r := gin.Default()
	r.GET("/hello", func(c *gin.Context) {
		c.JSON(http.StatusOK, gin.H{
			"message": "Hello  world",
		})
	})
	err := r.Run(":9090")
	if err != nil {
		panic(err)
	}
}
