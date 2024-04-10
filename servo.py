import tkinter as tk
import serial

class ServoControlApp:
    def __init__(self, master):
        self.master = master
        master.title("Control del Servomotor")

        self.label = tk.Label(master, text="Ingrese los grados:")
        self.label.pack()

        self.degrees_entry = tk.Entry(master)
        self.degrees_entry.pack()

        self.move_button = tk.Button(master, text="Mover", command=self.move_servo)
        self.move_button.pack()

        # Conexión con Arduino
        try:
            self.arduino = serial.Serial('COM9', 9600)
        except serial.SerialException:
            print("No se pudo establecer la conexión con Arduino.")

    def move_servo(self):
        try:
            degrees = int(self.degrees_entry.get())
        except ValueError:
            print("Por favor ingrese un valor numérico.")
            return

        if 0 <= degrees <= 180:
            self.arduino.write(str(degrees).encode())
            print(f"Se movió el servomotor a {degrees} grados.")
        else:
            print("Los grados deben estar en el rango de 0 a 180.")

root = tk.Tk()
app = ServoControlApp(root)
root.mainloop()
