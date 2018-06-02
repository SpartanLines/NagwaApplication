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
    public partial class DonorForm : Form
    {
        int maxdno;
        int Amt;
        int Pid;
        string ddate;
        int don;
        Controller ControllerObj;
        public DonorForm()
        {
            InitializeComponent();
            ControllerObj = new Controller();
        }

        private void ViewCasesB_Click(object sender, EventArgs e)
        {
            ControllerObj = new Controller();
            DataTable DT = ControllerObj.ViewCases();
            dataGridView1.DataSource = DT;
            dataGridView1.Refresh();
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            
        }

        private void cardView1_Click(object sender, EventArgs e)
        {
           
        }

        private void gridControl1_Click(object sender, EventArgs e)
        {
           
        }

        private void dataGridView1_CellContentClick_1(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void dataGridView1_SelectionChanged(object sender, EventArgs e)
        {

            ControllerObj = new Controller();
            if (dataGridView1.CurrentCell.RowIndex != 0)
            {
                string amt = dataGridView1.Rows[dataGridView1.CurrentCell.RowIndex].Cells[6].Value.ToString();
                Amt = Convert.ToInt32(amt);
                string pid = dataGridView1.Rows[dataGridView1.CurrentCell.RowIndex].Cells[8].Value.ToString();
                Pid = Convert.ToInt32(pid);
                ddate = dataGridView1.Rows[dataGridView1.CurrentCell.RowIndex].Cells[5].Value.ToString();
            }
            else
                return;
           
            

        }

        private void DonateB(object sender, EventArgs e)
        {
            ControllerObj = new Controller();
            int k = ControllerObj.getmaxd();
            int c = ControllerObj.InsertDonation(507,k+1,Amt,ddate,Pid);
             if (c == 0)
            {
                MessageBox.Show("failed");
            }
            else
            {
                MessageBox.Show("successfully!");
             }
        }

        private void button7_Click(object sender, EventArgs e)
        {
            ControllerObj = new Controller();
            DataTable DT = ControllerObj.ViewDonations(507);
            dataGridView1.DataSource = DT;
            dataGridView1.Refresh();

        }
    }
}
