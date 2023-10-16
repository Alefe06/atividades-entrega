class Paciente {
    constructor(nome, peso, altura) {
        this.nome = nome;
        this.peso = peso;
        this.altura = altura;
    }

    imc() {
        return this.peso / (this.altura * this.altura);
    }

    diagnosticar() {
        const imc = this.imc();
        if (imc < 18.5) {
            return "Abaixo do peso";
        } else if (imc >= 18.5 && imc < 25) {
            return "Peso normal";
        } else if (imc >= 25 && imc < 30) {
            return "Sobrepeso";
        } else if (imc >= 30 && imc < 35) {
            return "Obesidade grau 1";
        } else if (imc >= 35 && imc < 40) {
            return "Obesidade grau 2";
        } else {
            return "Obesidade grau 3";
        }
    }
}

const listaPacientes = [
    new Paciente("Maria", 65, 1.70),
    new Paciente("João", 80, 1.75),
    new Paciente("Ana", 55, 1.60),
    new Paciente("Juca", 65, 1.73),
    new Paciente("Jeca", 95, 1.70),
    new Paciente("Joca", 55, 1.85),
];

const pacientesElement = document.getElementById("pacientes");

listaPacientes.forEach((paciente) => {
    const div = document.createElement("div");
    div.innerHTML = `<p><strong>Nome:</strong> ${paciente.nome}</p>
                     <p><strong>Peso:</strong> ${paciente.peso} kg</p>
                     <p><strong>Altura:</strong> ${paciente.altura} m</p>
                     <p><strong>IMC:</strong> ${paciente.imc().toFixed(2)}</p>
                     <p><strong>Diagnóstico:</strong> ${paciente.diagnosticar()}</p>`;
    pacientesElement.appendChild(div);
});