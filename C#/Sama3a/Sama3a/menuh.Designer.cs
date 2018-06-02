namespace MyProject
{
    partial class menuh
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.Addmed = new System.Windows.Forms.Button();
            this.Adddoc = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // Addmed
            // 
            this.Addmed.Location = new System.Drawing.Point(661, 12);
            this.Addmed.Name = "Addmed";
            this.Addmed.Size = new System.Drawing.Size(178, 54);
            this.Addmed.TabIndex = 0;
            this.Addmed.Text = "Add medicine";
            this.Addmed.UseVisualStyleBackColor = true;
            this.Addmed.Click += new System.EventHandler(this.Addmed_Click);
            // 
            // Adddoc
            // 
            this.Adddoc.Location = new System.Drawing.Point(661, 93);
            this.Adddoc.Name = "Adddoc";
            this.Adddoc.Size = new System.Drawing.Size(178, 50);
            this.Adddoc.TabIndex = 1;
            this.Adddoc.Text = "Add doctor";
            this.Adddoc.UseVisualStyleBackColor = true;
            this.Adddoc.Click += new System.EventHandler(this.Adddoc_Click);
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(661, 166);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(178, 48);
            this.button3.TabIndex = 2;
            this.button3.Text = "retrieve cases";
            this.button3.UseVisualStyleBackColor = true;
            // 
            // dataGridView1
            // 
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(12, 21);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.Size = new System.Drawing.Size(618, 409);
            this.dataGridView1.TabIndex = 3;
            this.dataGridView1.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellContentClick);
            // 
            // menuh
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(863, 521);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.Adddoc);
            this.Controls.Add(this.Addmed);
            this.Name = "menuh";
            this.Text = "menuh";
            this.Load += new System.EventHandler(this.menuh_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button Addmed;
        private System.Windows.Forms.Button Adddoc;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.DataGridView dataGridView1;
    }
}