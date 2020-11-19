<?php
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
  $allowed = array("jpg","jpeg","png","gif");
  if(in_array($file_actual_extension,$allowed))
  {
    if($file_error == 0)
    {
      if($file_size<10000000)
      {
        $file_name_new = uniqid('',true) .".".$file_actual_extension;
        $file_destination = "pics\\".$file_name_new;
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
    echo "You cannot upload filesof this type!";
  }
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.5.3/dist/css/bootstrap.min.css"
    integrity="sha384-TX8t27EcRE3e/ihU7zmQxVncDAy5uIKz4rEkgIXeMed4M0jlfIDPvg6uqKI2xXr2" crossorigin="anonymous">
  <title>Document</title>
<style>
  body{
    padding:5px;
  }
  </style>
   <script src="https://code.jquery.com/jquery-3.5.1.slim.min.js" integrity="sha384-DfXdz2htPH0lsSSs5nCTpuj/zy4C+OGpamoFVy38MVBnE+IbbVYUew+OrCXaRkfj" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/popper.js@1.16.1/dist/umd/popper.min.js" integrity="sha384-9/reFTGAW83EW2RDu2S0VKaIzap3H66lZH81PoYlFhbGU+6BZp6G7niu735Sk7lN" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@4.5.3/dist/js/bootstrap.min.js" integrity="sha384-w1Q4orYjBQndcko6MimVbzY0tgp4pWB4lZ7lr30WKz0vr/aWKhXdBNmNb5D92v7s" crossorigin="anonymous"></script>

</head>
<body>
  
  <h1 class="display-4">Gallery 0.1</h1>
  <div id="carouselExampleCaptions" class="carousel slide" data-ride="carousel">
  <ol class="carousel-indicators">
    <li data-target="#Verzweiflung_pt1" data-slide-to="0" class="active"></li>
    <li data-target="#exe_stops_working" data-slide-to="1"></li>
    <li data-target="#Verzweiflung_pt1" data-slide-to="2"></li>
  </ol>
  <div class="carousel-inner">
    <div class="carousel-item active">
      <img src="./pics/5fb5cb3520c6e3.91436359.jpg"class="d-block w-100" alt="makeitstop">
      <div class="carousel-caption d-none d-md-block">
        <h5>Verzweiflung_pt1</h5>
       
      </div>
    </div>
    <div class="carousel-item">
      <img src="./pics/5fb5c3de865d97.66153084.jpg"  class="d-block w-100" alt="pls">
      <div class="carousel-caption d-none d-md-block">
        <h5>webtech.exe stopped working </h5>
        
      </div>
    </div>
    <div class="carousel-item">
      <img src="./pics/5fb5cef697fec3.29587216.jpg" class="d-block w-100" alt="ty">
      <div class="carousel-caption d-none d-md-block">
        <h5>Verzweiflung_pt2</h5>
        
      </div>
    </div>
  </div>
  <a class="carousel-control-prev" href="#carouselExampleCaptions" role="button" data-slide="prev">
    <span class="carousel-control-prev-icon" aria-hidden="true"></span>
    <span class="sr-only">Previous</span>
  </a>
  <a class="carousel-control-next" href="#carouselExampleCaptions" role="button" data-slide="next">
    <span class="carousel-control-next-icon" aria-hidden="true"></span>
    <span class="sr-only">Next</span>
  </a>
</div>
  <form action ="gallery.php" method="POST" enctype="multipart/form-data">
<div class="form-row">
<h3>Formular zum Dateiupload</h3>
</div>
  <div class="form row">
  <div class="form-col">
  <input type="file" name = "file">

  <button type="submit" class="btn btn-primary" name="submit">Upload</button>
  </div>

  <div class="col-7">
    <?php
    $var=0;
    foreach(scandir(getcwd()."\\"."pics") as $value)
    {
      //if($var==2)
      if($value==".." || $value ==".")
      {
        continue;
      }
        
      $path=getcwd()."\\"."pics\\".$value;
      echo "<img class=\"img-thumbnail\" src=\".\\pics\\$value\" alt=\"Card image cap\" style=\"max-width: 33%; height:auto\">";
    }
      
    ?>
  </div>
</div>
</form>



</body>
</html>