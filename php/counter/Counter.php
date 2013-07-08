<?php

#$id = $_GET['id'];
$id = 388123732;
$redis = new Redis();
$redis->connect('127.0.0.1', 6379);
$redis->incr($id);
$count = $redis->get($id);
echo $count."\n";


