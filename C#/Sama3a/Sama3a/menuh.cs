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
    public partial class menuh : Form
    {
        Controller controllerObj;
        public menuh()
        {
            InitializeComponent();
            controllerObj = new Controller();
             hospital h = new hospital();
            int hid = h.getHID();
            
        }

        private void Addmed_Click(object sender, EventArgs e)
        {
            addmed a = new addmed();
            a.Show();
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void menuh_Load(object sender, EventArgs e)
        {
            hospital h = new hospital();
            int hid = h.getHID();
            dataGridView1.Show();
            DataTable dt = controllerObj.getdoc(hid);
            dataGridView1.DataSource = dt;
            dataGridView1.Refresh();
        }

        private void Adddoc_Click(object sender, EventArgs e)
        {
            adddoctor b = new adddoctor();
                b.Show();
        }
    }
}
