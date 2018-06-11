function verificacaoformulario() {
    var form = document.getElementById('formulario');
    for (let i = 0; i < form.elements.length - 1; i += 2) {
        var nome = form.elements[i].value;
        var idade = form.elements[i + 1].value;
        var erro = false;
        var contador = 1;
        var mensagemErro = "Erro: \n";

        if (!/^[a-zA-Z]+$/.test(nome)) {
            erro = true;
            mensagemErro = mensagemErro.concat("-Nome inválido\n");
        }
        if (!idade.match(/^\d{4}-\d{2}-\d{2}$/)) {
            erro = true;
            mensagemErro = mensagemErro.concat("-Data inválida\n");
        }
        if(nome=="" && idade=="") {
            erro = falso;
        }

        //Debug: console.log(nome + ' ' + idade);

        if (erro) {
            alert(mensagemErro);
            return false;
            break;
        }
    }
}
