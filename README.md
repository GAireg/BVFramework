# Mein Framework für das Bldverarbeitungs Praktikum

Was dieses Framework kann / übernimt: 
 - Auswahl der Aufgabe
 - Öffnen von Bildern
 - Öffnen der Kamera
 - Ausgabe von Bildern

 ## Wie eine Aufgabe aufgebaut ist / erstellt wird:
 
 siehe WidgetAufgabe1 als beispiel

 Eine Aufgabe besteht aus einer Qt Formular-Klasse als Widget. Die UI elemente können auf dem Widget nach alt bekannten schemata angeordnet werden, dafür empfehlen sich Horizontal und vertical layout.

 Die Aufgabenklasse wird nicht mehr vom QWidget abgeletitet, sondern von WidgetAufgaben. 

 In der Aufgabe implementiert man die Methode updateLayout, die für jeden neuen Kameraframe / für jedes geöffnete Bild aufgerufen wird.

 In MainWindow.cpp muss die neue Aufgabe in den switch bei zeile 38 eingetragen werden
