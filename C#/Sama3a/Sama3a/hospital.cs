using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MyProject
{
    public partial class hospital : Form
    {
        Controller controllerObj;
        public hospital()
        {
            InitializeComponent();
            controllerObj = new Controller();
        }

        private void hospital_Load(object sender, EventArgs e)
        {

        }

        private void signup_Click(object sender, EventArgs e)
        {
            signuph a = new signuph();
                a.Show();
        }
        static int hid;
        public int getHID()
        {
            
            return hid;
        }

        private void signin_Click(object sender, EventArgs e)
        {
            // patient_main p = new patient_main();
            //p.Show();
            if (textBox1.Text == "" || password.Text == "")//validation part
            {
                MessageBox.Show("Please, insert all values");
            }
            else
            {
                int r = controllerObj.loginh(textBox1.Text.ToString(), password.Text.ToString());
                if (r > 0)
                // 
                {
                    hid = r;
                    MessageBox.Show("you loged in successfuly");
                    menuh a = new menuh();
                    a.Show();
                }
                else
                {
                    MessageBox.Show("Username or Password incorrect. Please try again");

                }
            }
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
