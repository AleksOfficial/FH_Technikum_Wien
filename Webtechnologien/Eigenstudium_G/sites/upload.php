<?php
//Youtube vid: https://www.youtube.com/watch?v=JaRq73y5MJk&t=225s
if (isset($_POST['submit']))
{
  $file = $_FILES['file'];

  $file_name = $_FILES['file']['name'];
  $file_tmp_name = $_FILES['file']['tmp_name'];
  $file_size = $_FILES['file']['size'];
  $file_error = $_FILES['file']['error'];
  $file_type = $_FILES['file']['type'];

  $file_name_exploded = explode(".",$file_name);
  $file_actual_extension = strtolower(end($file_name_exploded));

  $file_destination =$path."\\".$file_name_exploded[0].".".$file_actual_extension;

  $allowed = array("jpg","jpeg","png");

  if(!file_exists($file_destination))
  {
    if($file_error == 0)
    {
      if($file_size<500000)
      {
        //$file_name_new = uniqid('',true) .".".$file_actual_extension;
        
        var_dump($file_destination);
        move_uploaded_file($file_tmp_name,$file_destination);
      }
      else
      {
        echo "Your file is too big!";
      }

    } else
    {
      echo "There was an error uploading your file!";
    }
  }
  else
  {
    echo "You cannot upload file in the directory twice!";
  }
}