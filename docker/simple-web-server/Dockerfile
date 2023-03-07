FROM golang:latest

WORKDIR /app

COPY . /app

RUN go mod download && go mod verify && go build -o main .
CMD ["./main"]