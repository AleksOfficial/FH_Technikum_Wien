var log = "";
function add_numbers()
{
  let var1 = parseInt(document.getElementById('number_1').value);
  let var2 = parseInt(document.getElementById('number_2').value);
  
  let result = var1 + var2;
  log +=var1 + " + " + var2 +" = " + result+"<br>";
  document.getElementById("result").innerHTML = result;
  print_log();
}
function subtract_numbers()
{
  
  let var1 = parseInt(document.getElementById('number_1').value);
  let var2 = parseInt(document.getElementById('number_2').value);
  let result = var1 - var2;
  log +=var1 + " - " + var2 +" = " + result+"<br>";
  document.getElementById("result").innerHTML = result;
  print_log();
}
function divide_numbers()
{
  
  let var1 = parseInt(document.getElementById('number_1').value);
  let var2 = parseInt(document.getElementById('number_2').value);
  let result;
  
  if(var2)
  {
    result = var1 / var2;
  }
    
  else{ result = "NaN";}
  document.getElementById("result").innerHTML = result;
  log +=var1 + " / " + var2 +" = " + result+"<br>";
  print_log();
}
function multiply_numbers()
{
  
  let var1 = parseInt(document.getElementById('number_1').value);
  let var2 = parseInt(document.getElementById('number_2').value);
  let result = var1 * var2;
  log +=var1 + " * " + var2 +" = " + result+"<br>";
  print_log();
  document.getElementById("result").innerHTML = result;
}
function print_log()
{
  let value = "";
  //log.forEach(element => value+=element + "<br>");
  document.getElementById("log").innerHTML = log;
}
