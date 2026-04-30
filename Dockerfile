FROM gcc:latest

WORKDIR /app

COPY . .

RUN g++ vaja2.cpp -o vaja2

CMD ["./vaja2", "tests/test1_input.txt"]
