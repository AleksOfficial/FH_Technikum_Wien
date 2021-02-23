<?php
include "./sites/dropbox_class.php";
include "./sites/gallery_class.php";
session_start();
$users = array("admin"=>"admin","goellig"=>"123","Threebuns"=>"asdf1234","eichhoernchen"=>"123");

if(isset ($_POST['keep_logged_in']))
  $_COOKIE['staylogged']=setcookie("staylogged",true,time()+600,"/");




if(!isset($_SESSION['logged']))
{
  $_SESSION['logged'] =false;
}


if(isset($_GET['sess']))
{
  $_SESSION['logged'] = false;
  setcookie("staylogged",true,time()-3600,"/");
  session_destroy();
}
if(isset($_POST['username']) && isset($_POST['password']))
{
  foreach ($users as $key => $value)
  {
    if($_POST['username'] == $key && $_POST['password'] == $value)
    {
      $allowed_data=array("jpg","jpeg","png");
      $_SESSION['username'] = $key;
      $_SESSION['password'] = $value;
      $_SESSION['logged'] = true;
      $_SESSION['filesystem']=new Verzeichnis($_SESSION['username'],$allowed_data);
    }    
  }
}
?>