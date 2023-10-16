function calcularTempoVoo() {
    let distancia = parseFloat(document.getElementById("distancia").value);

    if (!isNaN(distancia) && distancia > 0) {
        let velocidadeCruzeiro = 900;
        let tempoVoo = distancia / velocidadeCruzeiro;

        document.getElementById("resultado").textContent = `Tempo de voo: ${tempoVoo.toFixed(2)} horas`;
    } else {
        document.getElementById("resultado").textContent = "Erro: Insira uma distância válida em quilômetros.";
    }
}