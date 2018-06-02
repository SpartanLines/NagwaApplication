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
    public partial class AdminForm : Form
    {
        Controller ControllerObj;

        public AdminForm()
        {
            ControllerObj= new Controller();
            InitializeComponent();
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void AdminForm_Load(object sender, EventArgs e)
        {
       
        }

        private void LoginB_Click(object sender, EventArgs e)
        {
            ControllerObj = new Controller();
            int c = ControllerObj.AdminLogin(UnameTB.Text, textBox1.Text);
            if (c == 0)
            {
                MessageBox.Show("failed");
            }
            else
            {
                MessageBox.Show("successfully!");
            }

         
        }

        private void UnameTB_TextChanged(object sender, EventArgs e)
        {
        
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
        
        }

        private void SignupB_Click(object sender, EventArgs e)
        {
            ControllerObj = new Controller();
            int c = ControllerObj.AdminInsert(UnameTB.Text,textBox1.Text,textBox2.Text);
             if (c == 0)
            {
                MessageBox.Show("failed");
            }
            else
            {
                MessageBox.Show("successfully!");
             }
        }
        }
    }
