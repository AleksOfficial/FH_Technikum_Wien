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
    <?php
  $var=0;
    foreach(scandir(getcwd()."\\"."pics") as $value)
    {
      //if($var==2)
      if($value==".." || $value ==".")
      {
        continue;
      }        
      echo '<li data-target="#carouselExampleCaptions" data-slide-to="'.$var. ($var==0 ?'" class="active"></li>':'"></li>');
      $var++;
    }
    ?>
  </ol>
  <div class="carousel-inner">
  <?php
  $var=0;
    foreach(scandir(getcwd()."\\"."pics") as $value)
    {
      
      if($value==".." || $value ==".")
      {
        continue;
      }
      $path="./pics/".$value;
      echo '
      <div class="carousel-item'.($var ==0 ? ' active">':'">').'
      <img src="'.$path.'"class="d-block w-100" alt="Bild'.$var.'">
      <div class="carousel-caption d-none d-md-block">
        <h5>Bild'.$var.'</h5>
      </div>
    </div>';        
      $var++;
    }
    ?>
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