function calcularAumento() {
    let nomeMercadoria = document.getElementById("nomeMercadoria").value;
    let precoMercadoria = parseFloat(document.getElementById("precoMercadoria").value);

    if (!isNaN(precoMercadoria) && precoMercadoria >= 0) {
        let aumento = precoMercadoria * 0.05; // Aumento de 5%
        let novoPreco = precoMercadoria + aumento;

        document.getElementById("resultado").textContent = `Nome da Mercadoria: ${nomeMercadoria}, Novo Preço: R$ ${novoPreco.toFixed(2)}`;
    } else {
        document.getElementById("resultado").textContent = "Erro: Insira um preço válido (não negativo).";
    }
}