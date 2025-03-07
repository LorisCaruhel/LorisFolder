<?php
$ftpConnect = ftp_connect("localhost", 9021, 90);
$ftpLogin = ftp_login($ftpConnect, "bibliotekr", "poipoi");

if($ftpLogin) {
    while(TRUE) {
        echo "Connection ftp réussi !\n";
        sleep(5);
    }
}