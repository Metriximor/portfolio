function soma(a, b) {
    return a + b;
}

function sub(a, b) {
    return a - b;
}

function multi(a, b) {
    return a * b;
}

function div(a, b) {
    if (b == 0) {
        return "Impossível dividir por 0";
    } else {
        return a / b;
    }
}

function calculadora() {
    var form = document.getElementById("calc");
    var i;
    var foper = parseFloat(form.elements[0].value);
    var oper = document.getElementsByName('operando');
    for (i = 0, length = oper.length; i < length; i++) {
        if (oper[i].checked) {
            // do whatever you want with the checked radio
            oper = oper[i].value;

            // only one radio can be logically checked, don't check the rest
            break;
        }
    }
    var soper = parseFloat(form.elements[5].value);
    var res;

    if (oper === "+") {
        res = soma(foper, soper);
    } else if (oper === "-") {
        res = sub(foper, soper);
    } else if (oper === "*" || oper === "x") {
        res = multi(foper, soper);
    } else if (oper === "/") {
        res = div(foper, soper);
    }

    //Resultado
    document.getElementById("resultado").innerHTML = foper + oper + soper + "=" + res;
}
