FROM gcc:latest

WORKDIR /app

COPY . .

RUN g++ main.cpp -o program

CMD ["./program", "tests/test1_input.txt"]