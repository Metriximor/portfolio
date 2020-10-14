let clock = new Date();
let horas = clock.getHours();
let min = clock.getMinutes();
document.write("Relógio: " + horas + "h" + min + "m" + "<br>");
if ((horas < 12) || (horas == 12 && min <= 1)) {
    document.writeln("Bom dia");
} else if ((horas == 12 && min <= 1) || (horas <= 19)) {
    document.writeln("Boa tarde");
    document.write("<style> body { background-color:rgb(128,128,128); color:blue;} </style>");
} else if ((horas == 19 && min <= 1) || (horas < 23)) {
    document.writeln("Boa noite");
    document.write("<style> body { background-color:black; color:white;} </style>");
} else if ((horas == 23)) {
    document.write("Durma bem");
}
