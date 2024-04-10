import tkinter as tk
import serial
import time

class MotorControlApp:
    def __init__(self, master):
        self.master = master
        master.title("Control del Motor DC")

        self.label = tk.Label(master, text="Valor de Motor:")
        self.label.pack()

        self.dutyCycle_var = tk.StringVar()
        self.dutyCycle_label = tk.Label(master, textvariable=self.dutyCycle_var)
        self.dutyCycle_label.pack()

        self.start_button = tk.Button(master, text="Iniciar", command=self.start_motor)
        self.start_button.pack()

    def start_motor(self):
        arduino = serial.Serial('COM6', 9600)  # Reemplaza 'COM3' por el puerto donde está conectado tu Arduino
        time.sleep(2)  # Espera a que se establezca la conexión
        arduino.flushInput()

        while True:
            arduino.write(b'1')  # Envía un byte para indicar al Arduino que inicie el programa
            time.sleep(1)  # Espera un segundo para que Arduino realice las operaciones
            response = arduino.readline().decode('utf-8').strip()  # Lee la respuesta del Arduino
            if response == 'Fin del ciclo':
                break

            self.dutyCycle_var.set(response)  # Actualiza el valor de dutyCycle en la interfaz
            self.master.update()  # Actualiza la interfaz gráfica

        arduino.close()
        self.dutyCycle_var.set("Ciclo completado")  # Actualiza la interfaz al final del ciclo

root = tk.Tk()
app = MotorControlApp(root)
root.mainloop()
