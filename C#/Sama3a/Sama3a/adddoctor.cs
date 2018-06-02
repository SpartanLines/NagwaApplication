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
    public partial class adddoctor : Form
    {
        Controller controllerObj;
        public adddoctor()
        {
            InitializeComponent();
            controllerObj = new Controller();
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void sign_Click(object sender, EventArgs e)
        {
           
            hospital h = new hospital();
            int hid = h.getHID();
            int r = controllerObj.Insertwh(docid, hid, textBox2.Text.ToString(), Convert.ToInt32(textBox5.Text), Convert.ToInt32(textBox6.Text), Convert.ToInt32(textBox7.Text), Convert.ToInt32(textBox4.Text));
        }

        private void adddoctor_Load(object sender, EventArgs e)
        {
            dataGridView1.Show();
            DataTable dt = controllerObj.disp();
            dataGridView1.DataSource = dt;
            dataGridView1.Refresh();
        }
        static int docid;
        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            int row = dataGridView1.SelectedCells[0].RowIndex;
            docid =Convert.ToInt16( dataGridView1.Rows[row].Cells[0].Value);
        }
    }
}
