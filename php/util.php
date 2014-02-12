<?php
$password = 'afdsab2351gfs';

if (preg_match('/\d+/',$password) && preg_match('/[[:alpha:]]+/', $password) && preg_match('/[[:punct:]]+/', $password)) {
    echo 'suc';
} else {
    echo 'fail';
}
