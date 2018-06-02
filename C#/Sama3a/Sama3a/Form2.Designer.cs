namespace MyProject
{
    partial class Form2
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
            this.AmtDonatedTB = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.DonateB = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // AmtDonatedTB
            // 
            this.AmtDonatedTB.Location = new System.Drawing.Point(63, 66);
            this.AmtDonatedTB.Name = "AmtDonatedTB";
            this.AmtDonatedTB.Size = new System.Drawing.Size(100, 22);
            this.AmtDonatedTB.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(45, 29);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(148, 17);
            this.label1.TabIndex = 1;
            this.label1.Text = "Amount to be donated";
            // 
            // DonateB
            // 
            this.DonateB.Location = new System.Drawing.Point(303, 86);
            this.DonateB.Name = "DonateB";
            this.DonateB.Size = new System.Drawing.Size(112, 36);
            this.DonateB.TabIndex = 2;
            this.DonateB.Text = "Donate";
            this.DonateB.UseVisualStyleBackColor = true;
            this.DonateB.Click += new System.EventHandler(this.DonateB_Click);
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(496, 321);
            this.Controls.Add(this.DonateB);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.AmtDonatedTB);
            this.Name = "Form2";
            this.Text = "Form2";
            this.Load += new System.EventHandler(this.Form2_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox AmtDonatedTB;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button DonateB;
    }
}