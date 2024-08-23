from qiskit import QuantumCircuit

circuit = QuantumCircuit(3, 3)

circuit.x(1)
circuit.h(range(3))
circuit.cx(0, 1)

circuit.z(2)

circuit.measure([1, 2], [1, 2])

print("\nNew Circuit:")
print(circuit)