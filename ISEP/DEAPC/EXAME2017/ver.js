function verificacao() {
    var comp = document.getElementById("comp").value;
    var larg = document.getElementById("larg").value;
    var numAnd = document.getElementById("numAnd").value;
    var altAnd = document.getElementById("altAnd").value;
    var numJanPor = document.getElementById("numJanPor").value;
    var arJanPor = document.getElementById("arJanPor").value;
    var rend = document.getElementById("rend").value;
    
    var altura = altAnd * numAnd;
    var excepcoes = numJanPor * arJanPor;
    var res = (comp * altura * 2) + (larg * altura * 2) - excepcoes;

    if((comp <= 0) || (larg <= 0) || (numAnd <= 0) || (altAnd <= 0) || (numJanPor <= 0) || (arJanPor <= 0) || (rend <= 0)) {
        alert("Não pode haver valores negativos, igual a 0 ou espaços sem estar preenchidos");
        return false;
    }
    if(res <= 0){
        alert("É impossivel ter mais janelas e portas do que parede");
        return false;
    }
}
