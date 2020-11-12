<?php

session_start();
if(isset($_GET['sess']))
{
  $_SESSION['logged'] = false;
  setcookie("staylogged",true,time()-3600,"/");
  session_destroy();
}
if(isset($_GET['tab']))
  $tab=$_GET['tab'];
else
  $tab=1;
if(isset($_GET['del']))
{
  unset($_SESSION['eingabe'][$_GET['del']]);
}
if(isset ($_POST['keep_logged_in']))
  $_COOKIE['staylogged']=setcookie("staylogged",true,time()+45,"/");

$username = "Karl";
$password = "123"; 
if(isset($_POST['username']))
  $_SESSION['username']=$_POST['username'];
  else
    $_SESSION['username']="";
if(isset($_POST['password']))
  $_SESSION['password']=$_POST['password'];
  else
    $_SESSION['password']="";
if(!isset($_SESSION['logged']))
  $_SESSION['logged']=false;

if(isset($_COOKIE['staylogged']))
{
  if($_COOKIE['staylogged'] && !isset($_GET['sess']))
    $_SESSION['logged'] = true;
}

if($_SESSION['username'] == $username && $_SESSION['password'] == $password)
{
  $_SESSION['logged'] = true;
}

?>
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.5.3/dist/css/bootstrap.min.css"
    integrity="sha384-TX8t27EcRE3e/ihU7zmQxVncDAy5uIKz4rEkgIXeMed4M0jlfIDPvg6uqKI2xXr2" crossorigin="anonymous">
    <style>
      .container{
        width: 800px;
      }
    </style>

  <title>Document</title>
</head>
<body>
  <div class="container">
<h1 class="display-4">Patientenverwaltung</h1>
<hr>
<nav>
  <ul class="nav nav-pills nav-justified">
    <?php
      echo '<li class="item"><a class="nav-link'.($tab == 1 ?' active"' :'"') .' href="index.php?tab=1">Home</a></li>';
      echo '<li class="item"><a class="nav-link'.($tab == 2 ?' active"' :'"') .' href="index.php?tab=2">Neuen Patienten anlegen</a></li>';
      echo '<li class="item"><a class="nav-link'.($tab == 3 ?' active"' :'"') .' href="index.php?tab=3">Patientendaten abrufen</a></li>';
      echo '<li class="item"><a class="nav-link'.($tab == 4 ?' active"' :'"') .' href="index.php?tab=4">Kontakt</a></li>';
      echo ($_SESSION['logged'] ? '<li class="item"><a class="nav-link" href="index.php?sess=1&tab=3">Logout</a></li>':"");
  ?>
  </ul>
    </nav>
  <?php
    if($tab==1)
    {
      include "./sites/home.php";
    }
    else if($tab==2)
    {
      include "./sites/neuerpatient.php";
    }
    else if($tab==3)
    {
      //login or show_data
      include "./sites/patientendaten.php";
    }
    else if($tab==4)
    {

      include "./sites/impressum.php";
    }
    else
    {
      include "/.sites/home.php";
    }

  ?>
  </div>
</body>
</html>