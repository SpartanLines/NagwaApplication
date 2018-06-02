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
    public partial class Question : Form
    {
        public Question()
        {
            InitializeComponent();
        }

        private void Question_Load(object sender, EventArgs e)
        {
            int bot = label1.Bottom;
            for (int i = 1; i < 20; i++)
            {
                Label l = new Label();
                l.Top = bot + 50 * i;
                l.Show();
                l.Text = "OMAE WA MOU SHINDERU";
                this.Controls.Add((Label)l);
            }

        }

    }
}