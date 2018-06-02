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
    public partial class DonorLogin : Form
    {
        Controller Controllerobj;
        public DonorLogin()
        {
            InitializeComponent();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            string username = textBox1.Text;
            string password = textBox2.Text;
            Controllerobj = new Controller();
            DataTable dt = Controllerobj.DonorLogin(username, password);
            if (dt == null)
            {
                MessageBox.Show("Wrong username or password");
            }
            else
            {
                string id = dt.Rows[0][0].ToString();
                int ID;
                int.TryParse(id, out ID);
                Form1 f = new Form1();
                f.Top = this.Top;
                f.Show();
                this.Hide();
            }

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}
