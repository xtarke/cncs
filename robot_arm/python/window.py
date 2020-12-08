from tkinter import *
from tkinter.ttk import * # Frame, Label, Entry, Button
from tkinter import scrolledtext 

import serial.tools.list_ports

class main_window(Frame):

    dict_jog = {'up': '$J=G91 Y+% F100000',\
                'down': '$J=G91 Y-% F100000',\
                'left': '$J=G91 X+% F100000',\
                'right': '$J=G91 X-% F100000',
                'z_up': '$J=G91 Z+% F100000',
                'z_down': '$J=G91 Z-% F100000'}    

    def __init__(self):
        super().__init__()

        self.initUI()
        
        self.serial_cnc = None
    
    def initUI(self):

        self.master.title('Controle robô')
        self.pack(fill=BOTH, expand=True)

        frm_01 = Labelframe(self, text='Serial')
        frm_01.pack(fill=X)
        
        frm_01.columnconfigure(0, pad=3)
        frm_01.columnconfigure(1, pad=3)
        frm_01.rowconfigure(0, pad=3)
        frm_01.rowconfigure(1, pad=3)
        frm_01.rowconfigure(2, pad=3)
        frm_01.rowconfigure(3, pad=3)
      
        lbl_01 = Label(frm_01, text='Analisador:', width=10)
        lbl_01.grid(row=0, column=0)
        
        self.cmb_analyzer = Combobox(frm_01, width=25)
        self.cmb_analyzer.grid(row=0, column=1)
        
        btn_open_analyzer = Button(frm_01, text='Abrir')
        btn_open_analyzer.grid(row=0, column=2)
                
        btn_refresh = Button(frm_01, text='Atualizar')
        btn_refresh.grid(row=0, column=3)
        btn_refresh['command'] = self.list_serial
              
        lbl_02 = Label(frm_01, text='CNC:', width=10)
        lbl_02.grid(row=1, column=0)

        self.cmb_cnc = Combobox(frm_01, width=25)
        self.cmb_cnc.grid(row=1, column=1)
        
        self.btn_open_cnc = Button(frm_01, text='Abrir')
        self.btn_open_cnc.grid(row=1, column=2)
        self.btn_open_cnc['command'] = self.open_serial_cnc

        notebook = Notebook(self)
        notebook.pack(fill=BOTH, expand=True)
       
        frm_ctrls = Frame(notebook)
        frm_ctrls.pack(fill=BOTH, expand=True)
                
        notebook.add(frm_ctrls, text='Controle')   
        
        frm_ctrls.columnconfigure(0, pad=3)
        frm_ctrls.columnconfigure(1, pad=3)
        frm_ctrls.columnconfigure(2, pad=3)
        frm_ctrls.columnconfigure(3, pad=3)
        frm_ctrls.columnconfigure(4, pad=3)
        
        frm_ctrls.rowconfigure(0, pad=3)
        frm_ctrls.rowconfigure(1, pad=3)
        frm_ctrls.rowconfigure(2, pad=3)
        frm_ctrls.rowconfigure(3, pad=3)
        frm_ctrls.rowconfigure(3, pad=7)
        frm_ctrls.rowconfigure(4, pad=7)
        frm_ctrls.rowconfigure(5, pad=7)
        frm_ctrls.rowconfigure(6, pad=7)
        frm_ctrls.rowconfigure(7, pad=7)
    
        lbl_03 = Label(frm_ctrls, text='Y:')
        lbl_03.grid(row=0, column=2)
        
        lbl_04 = Label(frm_ctrls, text='X:')
        lbl_04.grid(row=2, column=0)
        
        lbl_05 = Label(frm_ctrls, text='Z:')
        lbl_05.grid(row=0, column=4)
            
        # First row
         
        btn_dig_no = Button(frm_ctrls, text=u'\u25F8')
        btn_dig_no.grid(row=1, column=1)
        
        btn_up = Button(frm_ctrls, text= u'\u25B2')
        btn_up.grid(row=1, column=2)
        btn_up['command'] = lambda arg1=self.dict_jog['up'] : self.cnc_jog(arg1)
        
        btn_dig_ne = Button(frm_ctrls, text=u'\u25F9')
        btn_dig_ne.grid(row=1, column=3)
        
        btn_z_up_btn = Button(frm_ctrls, text= u'\u25B2')
        btn_z_up_btn.grid(row=1, column=4)
        btn_z_up_btn['command'] = lambda arg1=self.dict_jog['z_up'] : self.cnc_jog(arg1)
        
        # Second row
        
        btn_left_btn = Button(frm_ctrls, text=u'\u25C0')
        btn_left_btn.grid(row=2, column=1)
        btn_left_btn['command'] = lambda arg1=self.dict_jog['left'] : self.cnc_jog(arg1)
        
        btn_home_btn = Button(frm_ctrls, text=u'\u25EF')
        btn_home_btn.grid(row=2, column=2)
        
        btn_right_btn = Button(frm_ctrls, text=u'\u25B6')
        btn_right_btn.grid(row=2, column=3)
        btn_right_btn['command'] = lambda arg1=self.dict_jog['right'] : self.cnc_jog(arg1)
        
        # Thir row        
        btn_diag_so = Button(frm_ctrls, text=u'\u25FA')
        btn_diag_so.grid(row=3, column=1)
        
        btn_down = Button(frm_ctrls, text=u'\u25BC')
        btn_down.grid(row=3, column=2)
        btn_down['command'] = lambda arg1=self.dict_jog['down'] : self.cnc_jog(arg1)
        
        btn_diag_se = Button(frm_ctrls, text=u'\u25FF')
        btn_diag_se.grid(row=3, column=3)
                
        btn_z_down = Button(frm_ctrls, text=u'\u25BC')
        btn_z_down.grid(row=3, column=4)
        btn_z_down['command'] = lambda arg1=self.dict_jog['z_down'] : self.cnc_jog(arg1)
        
        # Step size combobox
        self.cmb_step = Combobox(frm_ctrls, width=5)
        self.cmb_step.grid(row=2, column=4)
        self.cmb_step['values'] = ['2','1','0.1']
        self.cmb_step.current(1)        
        
        lbl_06 = Label(frm_ctrls, text='Log:', width=50)
        lbl_06.grid(row=4, column=0,columnspan=6)
                
        self.txt_log = scrolledtext.ScrolledText(frm_ctrls, width=55, height=10)
        self.txt_log.grid(row=5, column=0, columnspan=5, rowspan=2)
        
        lbl_07 = Label(frm_ctrls, text='Comando:', width=8)
        lbl_07.grid(row=7, column=0) #columnspan=1)
        
        self.ent_cmd = Entry(frm_ctrls, width=25)
        self.ent_cmd.grid(row=7, column=1, columnspan=3)        
        self.ent_cmd.bind('<Return>', self.comp_s)
        
        self.btn_send_cmd = Button(frm_ctrls, text='Enviar')
        self.btn_send_cmd.grid(row=7, column=4)
        self.btn_send_cmd['command'] = self.send_cmd
        
        self.list_serial()
        
    def cnc_jog(self, jog_cmd_string):
        step = self.cmb_step.get()        
        jog_cmd_string = jog_cmd_string.replace('%', step)        
        print(jog_cmd_string)
        
        if (self.serial_cnc != None):
            if (self.serial_cnc.is_open):
                cmd = str(jog_cmd_string + '\n').encode()
                self.serial_cnc.write(cmd)
                
                data = self.serial_cnc.read_until('ok\n\r')
                self.txt_log.insert(END,data)
                
                self.txt_log.see(END)
    
    def comp_s(self, event):
        self.send_cmd()       

    def list_serial(self):         
        ports = serial.tools.list_ports.comports()
        
        print('Detected serial ports:')
        for i in ports:
            print(str(i))
        
        self.cmb_analyzer['values'] = ports
        self.cmb_analyzer.set('Escolha...')
        
        self.cmb_cnc['values'] = ports
        self.cmb_cnc.set('Escolha...')
        
    def send_cmd(self):
        if (self.serial_cnc != None):
            if (self.serial_cnc.is_open): 
                cmd = str(self.ent_cmd.get() + '\n').encode()
                self.serial_cnc.write(cmd)
                
                data = self.serial_cnc.read_until('ok')
                self.txt_log.insert(END,data)
                
                self.txt_log.see(END)
            
                
    def open_serial_cnc(self):        
        
        com_port =  self.cmb_cnc.get()        
        com_port = com_port.split()
        
        if (self.serial_cnc != None):
            if (self.serial_cnc.is_open):
                self.serial_cnc.close()
                self.btn_open_cnc['text'] = 'Abrir'
                print('Fechando: ' + com_port[0])
                self.serial_cnc = None
        else:
            try:
                self.serial_cnc = serial.Serial(com_port[0], 115200, timeout=0.5)
                self.btn_open_cnc['text'] = 'Fechar'
                print('Abrindo: ' + com_port[0])
            
            except Exception as e:
                sys.stderr.write('--- ERROR opening new port: {} ---\n'.format(e))
                # new_serial.close()
            

def main():

    root = Tk()
    root.geometry('600x500+300+300')
    app = main_window()
    root.mainloop()


if __name__ == '__main__':
    main()