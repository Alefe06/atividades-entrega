function calcularCilindro() {
    let raio = parseFloat(document.getElementById("raio").value);
    let altura = parseFloat(document.getElementById("altura").value);

    if (!isNaN(raio) && !isNaN(altura) && raio > 0 && altura > 0) {
        let areaSuperficie = 2 * Math.PI * raio * (raio + altura);
        let volumeCilindro = Math.PI * raio * raio * altura;

        document.getElementById("resultado").textContent = `Área da Superfície: ${areaSuperficie.toFixed(2)} cm², Volume do Cilindro: ${volumeCilindro.toFixed(2)} cm³`;
    } else {
        document.getElementById("resultado").textContent = "Erro: Insira valores válidos para raio e altura do cilindro.";
    }
}