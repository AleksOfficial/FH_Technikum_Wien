#!C:\ProgramData\Anaconda3\python.exe
print()
print('<!DOCTYPE html>')
print('<html lang="en">')
print(''' <head> <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <link href="style.css" rel="stylesheet" type="text/css">
  <title>I'M a PRICK</title></head>''')

#body tag
print('<body>')

#For loop
x = 1
print('<table>')
for i in range(3):
  print('<tr>')
  for j in range(5):
    if x%2:
      print('<td class=uneven>{}</td>'.format(x))
    else:
      print('<td class=even>{}</td>'.format(x))
    x+=1
  print('</tr>')
print('</table><br>')

#while loop
x,i = 1,0
print('<table>')
while i<3:
  print('<tr>')
  j=0
  while j<5:
    if x%2:
      print('<td class=uneven>{}</td>'.format(x))
    else:
      print('<td class=even>{}</td>'.format(x))
    x+=1
    j+=1
  print('</tr>')
  i+=1
print('</table><br>')


#there is no do-while loop in python. the easy way would be to execute that thing at least once manually and then initiallize a loop.
#but thats kinda tedious. I'll just leave it here. 
#I am so blown away by this. this is amazing. I didn't know that Apache and XAMPP was capable of doing this. 

print('</body>')
print('</html>')

 