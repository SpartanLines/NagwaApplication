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
    public partial class Form4 : Form
    {
        public Form4()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form3 r = new Form3();
            r.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form5 h = new Form5();
            h.Show();
        }
    }
}
