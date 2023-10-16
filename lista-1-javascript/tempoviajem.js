function calcularTempoViagem() {
    let velocidade = parseFloat(document.getElementById("velocidade").value);
    let distancia = parseFloat(document.getElementById("distancia").value);

    if (velocidade > 0) {
        let tempo = distancia / velocidade;
        document.getElementById("resultado").textContent = `Tempo necessário: ${tempo} horas`;
    } else {
        document.getElementById("resultado").textContent = "Erro: A velocidade deve ser maior que zero.";
    }
}