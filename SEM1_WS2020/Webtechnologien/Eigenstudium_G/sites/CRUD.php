<?php
//changing directory
if(isset($_SESSION['username']))
{
  $home="uploads\\".$_SESSION['username'];
}
$subpath ="";

if(isset($_GET['cd']))
{
  if($_GET['cd']=="..")
  {
    if(count($_SESSION['path'])>0)
    array_pop($_SESSION['path']);
  
  }
  else
  {
    array_push($_SESSION['path'],$_GET['cd']);
  }
}

foreach($_SESSION['path'] as $folder)
  {
    $subpath = $subpath.$folder."\\";
  }


$path=$home."\\".$subpath;
  //create directory
  if(isset($_POST['submit_folder']))
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
  }
//delete
  if(isset($_GET['del']))
  {
    chdir($path);
    $filepath=getcwd()."\\".$_GET['del'];
    if(file_exists($filepath))
    {
        if(is_dir($filepath))
          rmdir($filepath);
        else
          unlink($filepath);
  }
}
//Move_Directory

//return to home
chdir($backup_dir);
?>