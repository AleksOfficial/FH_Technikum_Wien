<?php

class Verzeichnis
{
  private $allowed_datatypes;
  private $path = ".\\uploads\\";
  private $subpath;
  private $total_path;
  function __construct($u_path, $allowed_datatypes)
  {
    $this->path = $this->path . $u_path;
    $this->allowed_datatypes = $allowed_datatypes;
    $this->total_path=$this->path;
    $this->subpath=array();
    
  }

  public function change_directory($input)
  {
    if ($input == "..") {
      if (count($this->subpath) > 0) {
        array_pop($this->subpath);
      }
    } else {
      array_push($this->subpath, $input);
    }
    $this->total_path = (count($this->subpath) > 0 ? $this->path . $this->construct_path() : $this->path);
  }

  public function construct_path()
  {
    $addon = "";
    foreach ($this->subpath as $x => $value) {

      $addon = $addon . "\\" . $value;
    }
    return $addon;
  }

  public function upload($file)
  {
    $file_name_exploded = explode(".", $file['name']);
    $file_extension = strtolower(end($file_name_exploded));
    $file_destination = $this->total_path . "\\" . $file_name_exploded[0] . ".".$file_extension;

    if (!file_exists($file_destination)) {
      if ($file['error'] === 0) {

        if (in_array($file_extension, $this->allowed_datatypes)) {
          move_uploaded_file($file['tmp_name'], $file_destination);
          echo $this->success('File successfully uploaded!');
        } else
          echo $this->error('Not allowed datatype uploaded!');
      }
    } else {
      echo $this->error('There was an error with your Upload!');
    }
  }
  public function createNewFolder($foldername)
  {
    if (!file_exists($this->total_path . "\\" . $foldername)) {
      mkdir($this->total_path . "\\" . $_POST['foldername']);
      echo $this->success('Folder Created!');
    } else
      echo $this->error('An error has occured! The folder already exists.');
  }
  public function delete($name)
  {
    $filepath = $this->total_path . "\\" . $name;
    if (file_exists($filepath)) {
      if (is_dir($filepath))
      {
        rmdir($filepath);
        echo $this->success('Folder deleted!');
      }

      else
      {
        unlink($filepath);
        echo $this->success('File deleted!');
      }
        
    }
  }
  //General Problem: by implementing 2 get functions, this leads to twice the time it needs to traverse the filefolder
  //It might be better to have a function that traverses the list once and creates 2 arrays. Then, depending on the file type, it gets inserted into the arrays
  public function getAllFiles()
  {
    $file_array=array();
    $scan_array = scandir($this->total_path);
    foreach($scan_array as $value)
    {
      $filepath = $this->total_path."\\".$value;
      if(!is_dir($filepath))
      {
        $file_data = pathinfo($filepath);
        $new_file = new Singlefile($file_data,0);
        if($new_file->error===0)
          array_push($file_array,$new_file);
        else
          echo $this->error('There was an error while reading a file... Perhaps the datatype wasnt allowed?');
      }
    }
    
    return $file_array;
  }

  public function getAllFolders()
  {
    $folder_array=array();
    $scan_array=scandir($this->total_path);
    foreach($scan_array as $value)
    {
      $filepath=$this->total_path."\\".$value;
      if(is_dir($filepath))
      {
        if($value!=".")
          array_push($folder_array,$value);
      }

    }
    return $folder_array;
  }
  //These two functions could be wrapped around an own class. similar to the one I learnt in Codecademy
  //Utils class, which prints out the messages needed. And they are called within the class.
  //This would divide the class further into it's bits so that this class focuses only on the directory stuff
  public function error($error_msg)
  {
    return '<div class="alert alert-danger" role="alert">
  '.$error_msg.'</div>';
  }
  public function success($success_msg)
  {
    return '<div class="alert alert-success" role="alert">
    '.$success_msg.'</div>';
  }
}

