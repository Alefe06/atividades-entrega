function realizarOperacoes() {
    let numero = parseInt(document.getElementById("numero").value);

    if (!isNaN(numero) && numero > 0) {
        let numeroMenosUm = numero - 1;
        let numeroMaisUm = numero + 1;

        document.getElementById("resultado").textContent = `n - 1 = ${numeroMenosUm}, n + 1 = ${numeroMaisUm}`;
    } else {
        document.getElementById("resultado").textContent = "Erro: Insira um número inteiro positivo e diferente de zero.";
    }
}