<?php

$dir ="uploads";
if (is_dir($dir)) {
  if ($dh = opendir($dir)) {
    var_dump($dh);
      while (($file = readdir($dh)) !== false) {
        var_dump($file);
      }
      closedir($dh);
  }
} /*facepalm*/
?>