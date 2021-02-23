<?php
//changing directory
/*
if(isset($_SESSION['username']))
{
  $home="uploads\\".$_SESSION['username'];
}
$subpath ="";*/

if(isset($_GET['cd']))
{
  $_SESSION['filesystem']->change_directory($_GET['cd']);
}
//Previous Implementation
/*
foreach($_SESSION['path'] as $folder)
  {
    $subpath = $subpath.$folder."\\";
  }
*/

//$path=$home."\\".$subpath;
  //create directory
  
  if(isset($_POST['submit_folder']))
  {
    if($_POST['foldername'])
      $_SESSION['filesystem']->createNewFolder($_POST['foldername']);
  }
  /*
  {
    //if($_POST['submit_folder'])
      //{
        chdir($path);
        if(!file_exists(getcwd()."\\".$_POST['foldername']))
        {
          mkdir(getcwd()."\\".$_POST['foldername']);
          echo '<p>Folder Created!</p>';
        }
        else
          echo '<p>An error has occured! The folder already exists.</p>';
      //}
  }*/
//delete

  if(isset($_GET['del']))
  {
    $_SESSION['filesystem']->delete($_GET['del']);
    /*
    chdir($path);
    $filepath=getcwd()."\\".$_GET['del'];
    if(file_exists($filepath))
    {
        if(is_dir($filepath))
          rmdir($filepath);
        else
          unlink($filepath);
    */
  }

//Move_Directory

//return to home

?>