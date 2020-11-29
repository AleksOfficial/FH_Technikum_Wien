<?php
//Youtube vid: https://www.youtube.com/watch?v=JaRq73y5MJk&t=225s
if (isset($_POST['submit']))
{
  if(isset($_FILES['file']))
  {
    $_SESSION['filesystem']->upload($_FILES['file']);
  }
}