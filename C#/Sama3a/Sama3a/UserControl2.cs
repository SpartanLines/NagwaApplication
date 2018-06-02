using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MyProject
{
    public partial class amount : UserControl
    {
        public amount()
        {
            InitializeComponent();
        }

        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            if(!String.IsNullOrWhiteSpace(textBox1.Text)& !String.IsNullOrWhiteSpace(textBox2.Text)& !String.IsNullOrWhiteSpace(textBox3.Text))
            {

            }
            else
            {

            }
        }
    }
}
