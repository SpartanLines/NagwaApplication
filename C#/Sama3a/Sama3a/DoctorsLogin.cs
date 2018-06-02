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
    public partial class DoctorsLogin : Form
    {
        Controller controllerobj;
        public DoctorsLogin()
        {
            InitializeComponent();
           
        }

        private void panel2_Paint(object sender, PaintEventArgs e)
        {

        }

        private void flowLayoutPanel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void DoctorsLogin_Load(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void label6_Click(object sender, EventArgs e)
        {
            
        }

        private void label8_Click(object sender, EventArgs e)
        {

        }

        private void label13_Click(object sender, EventArgs e)
        {

        }

        private void label12_Click(object sender, EventArgs e)
        {

        }

        private void textBox7_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox11_TextChanged(object sender, EventArgs e)
        {
            if (System.Text.RegularExpressions.Regex.IsMatch(textBox1.Text, "  ^ [0-9]"))
            {
                textBox1.Text = "";
            }
        }

        private void Phone_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!char.IsControl(e.KeyChar) && !char.IsDigit(e.KeyChar) && (e.KeyChar != '.'))
            {
                e.Handled = true;
            }
        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {
      
        }

        private void textBox5_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!char.IsControl(e.KeyChar) && !char.IsLetter(e.KeyChar) &&
         (e.KeyChar != '.'))
            {
                e.Handled = true;
                MessageBox.Show("Only Alphabets");
                
            }
        }

        private void textBox3_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!char.IsControl(e.KeyChar) && !char.IsLetter(e.KeyChar) &&
         (e.KeyChar != '.'))
            {
                e.Handled = true;
                MessageBox.Show("Only Alphabets");
            }
        }

        private void textBox6_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!char.IsControl(e.KeyChar) && !char.IsLetter(e.KeyChar) &&
         (e.KeyChar != '.'))
            {
                e.Handled = true;
                MessageBox.Show("Only Alphabets");
            }
        }

        private void textBox10_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!char.IsControl(e.KeyChar) && !char.IsLetter(e.KeyChar) &&
         (e.KeyChar != '.'))
            {
                e.Handled = true;
                MessageBox.Show("Only Alphabets");
            }
        }

        private void textBox9_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!char.IsControl(e.KeyChar) && !char.IsLetter(e.KeyChar) &&
         (e.KeyChar != '.'))
            {
                e.Handled = true;
                MessageBox.Show("Only Alphabets");
            }
        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        private void label11_Click(object sender, EventArgs e)
        {

        }

        private void label9_Click(object sender, EventArgs e)
        {

        }

        private void panel2_Paint_1(object sender, PaintEventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            string username = textBox1.Text;
            string password = textBox2.Text;
            controllerobj = new Controller();
            DataTable dt = controllerobj.DrLogin(username, password);
            if (dt == null)
            {
                MessageBox.Show("Wrong username or password");
            }
            else
            {
                string id = dt.Rows[0][0].ToString();
                int ID;
                int.TryParse(id, out ID);
                Form1 f = new Form1(ID);
                f.Top = this.Top;
                f.Show();
                this.Hide();
            }

            }


        private void button2_Click(object sender, EventArgs e)
        {
            foreach (Control child in this.Controls)
            {
                TextBox textBox = child as TextBox;
                if (textBox != null)
                {
                    if (!string.IsNullOrWhiteSpace(textBox.Text))
                    {
                        MessageBox.Show("Text box can't be empty");
                        break;
                    }

                }
            }
            string fname = textBox5.Text;
            string Minit = textBox3.Text;
            string Lname = textBox6.Text;
            string Speciality = textBox10.Text;
            string title = textBox9.Text;

            string gender = comboBox1.Text;
            int phoneno;
            string user = textBox7.Text;
            string pass = textBox4.Text;
            int.TryParse(Phone.Text, out phoneno);
            controllerobj = new Controller();
            DataTable dt = controllerobj.CheckDocuser(user);
            if (dt != null)
            {
                MessageBox.Show("User name already taken!");
            }
            else
            {
                controllerobj.InsertNewDoc(fname, Minit, Lname, Speciality, title, gender, phoneno);
                dt = controllerobj.fetchid(phoneno);
                int DOCTID;
                int.TryParse(dt.Rows[0][0].ToString(), out DOCTID);
                controllerobj.InsertDocUser(user, pass, DOCTID);

            }


        }


    }






}

