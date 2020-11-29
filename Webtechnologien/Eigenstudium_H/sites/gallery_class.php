<?php
  class Singlefile{
    public $filename;
    public $path;
    public $datatype;
    public $error;
    
    private $allowed_datatypes=array("jpg","jpeg","png","gif");

  function __construct($file,$upload)
  {
    if($upload)
    {
      $this->error=$file['error'];
      if($this->error==0)
      {
        
        $this->filename=$file['name'];
        $this->datatype=$this->set_datatype($this->filename);
        $this->path=$this->move_file($file['tmp_name']);
      }
      else
      {
        echo 'There was an Error during your upload!';
      }
    
    }
    else
    {

      $this->filename=$file['basename'];
      $this->path = $file['dirname'];
      $this->datatype=$this->set_datatype($this->filename);
    }


  }
  private function move_file($tmp_path)
  {
    $file_destination="./Pics/".$this->filename;
    move_uploaded_file($tmp_path,$file_destination);
    return $file_destination;
  }

  private function set_datatype($_filename)
  {
    $filename_exploded = explode(".",$_filename);
    $file_extension = strtolower(end($filename_exploded));
    if(in_array($file_extension,$this->allowed_datatypes))
    {
      $this->error=0;
      return $file_extension;
    }
    else
    {
    echo 'Error!';
    $this->error=1;
    }
  
  }

  public function full_filepath()
  {
    return $this->path."/".$this->filename;  
  }
}
  
?>