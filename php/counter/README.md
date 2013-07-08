
Counter
====

* 1. Install Redis

```text
>$ wget http://redis.googlecode.com/files/redis-2.6.14.tar.gz
>$ tar xzf redis-2.6.14.tar.gz
>$ cd redis-2.6.14
>$ make
>$ src/redis-server
```
* 2. Config the redis

```text
bind 127.0.0.1
save 60 1
```

* 3. Install phpredis module for php


