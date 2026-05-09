
FROM gcc:latest as builder
WORKDIR /app
COPY server.c .

RUN gcc server.c -o server
FROM debian:bookworm-slim
WORKDIR /app
COPY --from=builder /app/server .
EXPOSE 8080
CMD ["./server"]