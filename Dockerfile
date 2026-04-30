FROM gcc:latest

WORKDIR /app

COPY . .

RUN g++ vaja2.cpp -o vaja2

ENTRYPOINT ["./vaja2"]
